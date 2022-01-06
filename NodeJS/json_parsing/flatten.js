const {flatten} = require('flat');

myJson = {
	"id": "0001",
	"type": "donut",
	"name": "Cake",
	"ppu": 0.55,
	"batters":
		{
			"batter":
				[
					{ "id": "1001", "type": "Regular" },
					{ "id": "1002", "type": "Chocolate" },
					{ "id": "1003", "type": "Blueberry" },
					{ "id": "1004", "type": "Devil's Food" }
				]
		},
	"topping":
		[
			{ "id": "5001", "type": "None" },
			{ "id": "5002", "type": "Glazed" },
			{ "id": "5005", "type": "Sugar" },
			{ "id": "5007", "type": "Powdered Sugar" },
			{ "id": "5006", "type": "Chocolate with Sprinkles" },
			{ "id": "5003", "type": "Chocolate" },
			{ "id": "5004", "type": "Maple" }
		]
};

const flatten_json = flatten(myJson);

// console.log('Flattened JSON:', flatten_json);

const TO_FIND = 'Regular';

const keys = Object.keys(flatten_json);

var found = false;

for (let key of keys) {
    if (flatten_json[key] === TO_FIND) {
        console.log(`Found ${TO_FIND} at ${key}`);
        found = true;
        break;
    }
}

if (!found) {
    console.log(`Could not find ${TO_FIND}`);
}