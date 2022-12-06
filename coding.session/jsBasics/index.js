{
    // use let to initialize the variables
    let name = "Andrew";

    console.log(name);

    let firstName = "Andrew";
    let lastName;

    // use const if you dont want to change the value
    const interestRate = .3;
    // interestRate = 1;

    console.log(interestRate);
}
{
    // typeof 
    let name = 'Andrew'; // string literal
    let age = 19; // number literal
    let isApproved = true; // boolean literal
    let firstName = undefined; // object
    let selectedColor = null; // clear the value

    // Object literal
    let person = {
        name: 'Andrew',
        age: 19
    };

    // Acesss the object
    person.name = 'Jules';

    // other way [bracket notation]
    // use this if you dont know what object you want to get
    let selection = 'name';
    person['name'] = 'Andrew';

    console.log('Acessing the person name : ' + person.name);
}
{
    //array literals
    let selectedColor = ['red', 'blue', 'green'];
    selectedColor[3] = 1;
    console.log('Lenght of selectedColor : ' + selectedColor.length);
}
{
    // performing a task
    function greet(firstName, lastName) {
        console.log('Hellow ' + firstName + ' ' + lastName);
    }

    greet('Andrew Jules ', 'Miyajima');

    // calculate something
    // funtion with return value
    function square(number) {
        return number * number;
    }

    // let numberSquared = square(4);
    console.log('Square of 4 : ' + square(4));
}

