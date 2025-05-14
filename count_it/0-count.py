#!/usr/bin/python3
""" Module : count_it """
import praw
import re
from collections import defaultdict

def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively counts occurrences of keywords in hot post titles of a subreddit.

    Parameters:
        subreddit (str): The name of the subreddit.
        word_list (list): List of keywords to count.
        after (str): The 'after' parameter for pagination.
        counts (dict): Accumulator for keyword counts.
    """
    if counts is None:
        counts = defaultdict(int)

    # Initialize PRAW with your Reddit API credentials
    reddit = praw.Reddit(
        client_id='YOUR_CLIENT_ID',
        client_secret='YOUR_CLIENT_SECRET',
        user_agent='YOUR_USER_AGENT'
    )

    # Fetch the hot posts from the subreddit
    hot_posts = reddit.subreddit(subreddit).hot(limit=100, params={'after': after})

    # Process each post
    for post in hot_posts:
        title = post.title.lower()
        # Count occurrences of each keyword in the title
        for word in word_list:
            # Use regex to match whole words, ignoring case
            count = len(re.findall(r'\b' + re.escape(word.lower()) + r'\b', title))
            counts[word.lower()] += count

    # Check if there are more posts to fetch
    if hot_posts.after:
        count_words(subreddit, word_list, after=hot_posts.after, counts=counts)
    else:
        # Sort and print the results
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")
