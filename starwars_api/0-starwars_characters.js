#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a movie ID as a positional argument.');
  process.exit(1);
}

const filmUrl = `https://swapi.dev/api/films/${movieId}/`;

request(filmUrl, (err, res, body) => {
  if (err) {
    console.error('Error fetching film:', err);
    return;
  }

  if (res.statusCode !== 200) {
    console.error(`Failed to fetch film. Status code: ${res.statusCode}`);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  // Fetch character names in order
  characters.forEach((url) => {
    request(url, (charErr, charRes, charBody) => {
      if (charErr) {
        console.error('Error fetching character:', charErr);
        return;
      }

      if (charRes.statusCode === 200) {
        const character = JSON.parse(charBody);
        console.log(character.name);
      } else {
        console.error(`Failed to fetch character. Status code: ${charRes.statusCode}`);
      }
    });
  });
});

