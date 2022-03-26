function dividersInp() 
{
    let input = document.getElementById("input") as HTMLInputElement;
    let number = parseInt(input.value);
    var output = document.createElement("p");
    while(number > 0)
    {
        dividers(number);
        number--;
    }
    output.innerHTML = "Dividers of " + number + " are: ";
    document.body.appendChild(output);
}

function *dividers(number: number)
{
    let numCount, numDiv = 0;
    numDiv = number;
    while (numDiv > 0) {
        numCount = number % numDiv;
        if (numCount == 0) {
            console.log(numDiv);
            yield numDiv;
        }
        numDiv--;
    }
    return;
}