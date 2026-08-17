const accountId = 105090
let accountEmail = "ghost@google.com"
var accountPassword = "12345"
accountCity ="Mumbai"
let accountState;

accountEmail = "Ab@hc.com"
accountPassword = "22222"
accountCity ="Chennai"
/* 
prefer not use var 
bcoz of issue in block scope and function code
*/
console.log(accountId);
console.table([accountId, accountEmail,accountPassword,accountCity,accountState]);

