"use strict";
// Define a class
class Person {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
    // Define a method
    sayHello() {
        console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
    }
}
// Create an instance of the class
const person = new Person("John", 25);
// Call the method
person.sayHello();
