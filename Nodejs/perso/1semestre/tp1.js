const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
let dividende = 0;
let diviseur = 0;
let quotient = 0.0;

rl.question('Quel est le dividende ?  ', (answer1) => {
    dividende = parseInt(answer1);
});
rl.question('Quel est le diviseur ? ',(answer2) => {
    diviseur = parseInt(answer2);
});

quotient = dividende / diviseur;
console.log('Le quotient de la division est : ' + quotient);

