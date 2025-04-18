#!/usr/bin/node
const https = require('https');

function getJson(url) {
    return new Promise((resolve, reject) => {
        https.get(url, (resp) => {
            let data = '';

            // A chunk of data has been received.
            resp.on('data', (chunk) => {
                data += chunk;
            });

            // The whole response has been received.
            resp.on('end', () => {
                try {
                    const jsonData = JSON.parse(data);
                    resolve(jsonData);
                } catch (error) {
                    reject(new Error('Failed to parse JSON'));
                }
            });

        }).on('error', (err) => {
            reject(new Error(`Request failed: ${err.message}`));
        });
    });
}

async function getMovieCharacters(movieId) {
    const baseUrl = `https://swapi.dev/api/films/${movieId}/`;

    try {
        // Make a request to get the movie details
        const movieData = await getJson(baseUrl);
        const charactersUrls = movieData.characters;

        // Iterate over each character URL and get the character name
        for (const characterUrl of charactersUrls) {
            try {
                const characterData = await getJson(characterUrl);
                console.log(characterData.name);
            } catch (error) {
                console.error(`Failed to retrieve character data from ${characterUrl}: ${error.message}`);
            }
        }
    } catch (error) {
        console.error(`Failed to retrieve movie data for ID ${movieId}: ${error.message}`);
    }
}

// Get the movie ID from command line arguments
const movieId = process.argv[2];
if (!movieId) {
    console.log('Usage: node 0-starwars_characters.js <movie_id>');
    process.exit(1);
}

getMovieCharacters(movieId);

