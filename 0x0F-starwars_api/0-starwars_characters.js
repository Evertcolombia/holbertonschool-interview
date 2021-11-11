#!/usr/bin/node
const request = require('request');


const APIUrl = "https://swapi-api.hbtn.io/api/films/";

const options = {
    url: `https://swapi-api.hbtn.io/api/`,
    method: "GET",
    headers: {
        'Accept': 'application/json',
        'Accept-Charset': 'utf-8',
    }
};

const getFilmCharacters = () => {
    request(options, (err, res, body) => {
        let json = JSON.parse(body);
        json.characters.forEach((item) => {
            request(item, (err, res, body) => {
                let character = JSON.parse(body);
                console.log(character.name);
            });
        });
    });
};

getFilmCharacters();