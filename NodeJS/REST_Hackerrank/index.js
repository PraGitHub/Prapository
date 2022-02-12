const request = require('request');

function getTotalPages(url) {
    return new Promise((resolve, reject) => {
        request.get(url, (err, res, body) => {
            if (err) {
                reject(err);
            } else {
                try {
                    let total_pages = parseInt(JSON.parse(body).total_pages, 10);
                    resolve(total_pages);
                } catch (e) {
                    reject(e);
                }
            }
        })
    });
}

function getTotalGoalsAs (team, teamAs, year) {
    return new Promise ((resolve, reject) => {
        const baseUrl = `https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team${teamAs}=${team}`;
        let goals = 0;
        getTotalPages(baseUrl)
        .then((total_pages) => {
            // console.log("total_pages:", total_pages);
            let counter = total_pages;
            for (let i = 1; i <= total_pages; i++) {
                let url = `${baseUrl}&page=${i}`;
                request.get(url, (err, res, body) => {
                    if (err) {
                        reject(err);
                    }
                    try {
                        JSON.parse(body).data.forEach((match) => {
                            if (match[`team${teamAs}`].toLowerCase() === team.toLowerCase()) {
                                goals += parseInt(match[`team${teamAs}goals`]);
                                // console.log("goals:", goals);
                            }
                        });
                    } catch (e) {
                        reject(e);
                    }
                    counter -= 1;
                    if (counter == 0) {
                        resolve(goals);
                    }
                });
            }
        })
        .catch((err) => {
            console.log("Error getting total pages:", err);
        });
    });
}

async function getTotalGoals(team, year) {
    let goals = 0;
    goals += await getTotalGoalsAs(team, 1, year);
    goals += await getTotalGoalsAs(team, 2, year);
    console.log(`Total number of goals by ${team} in ${year} is ${goals}`);
}

async function getDraws(year) {
    let draws = 0;
    let max_goals = 20;
    for (let goal = 0; goal <= max_goals; goal++) {
        let url = `https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1goals=${goal}&team2goals=${goal}`;
        draws += await new Promise((resolve, reject) => {
            request.get(url, (err, res, body) => {
                let total = 0;
                try {
                    total = parseInt(JSON.parse(body).total);
                    
                } catch(e) {
                    reject(e);
                }
                resolve(total);
            });
        });
    }
    console.log(`Total number of drawn matches in ${year} is ${draws}`);
}

getTotalGoals("Barcelona", 2011);
getTotalGoals("Barcelona", 2012);
getTotalGoals("Barcelona", 2013);
getTotalGoals("Barcelona", 2014);
getTotalGoals("Barcelona", 2015);

getDraws(2011);
getDraws(2012);
getDraws(2013);
getDraws(2014);
getDraws(2015);

// setTimeout(() => {
//     console.log("Done!");
// }, 10000);

