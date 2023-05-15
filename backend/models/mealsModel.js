const mongoose = require('mongoose');


const mealModel = new mongoose.Schema({
    shortName: {type: mongoose.Schema.Types.String, required: true},
    name: {type: mongoose.Schema.Types.String, required: true},
    description: {type: mongoose.Schema.Types.String, required: false},
    availability: {type: mongoose.Schema.Types.Boolean, required:true, default: true},
    productsCount: {type: mongoose.Schema.Types.Number, required: true, default: 0},
    price: {type: mongoose.Schema.Types.Number, required: true, default: 0.0},
    ingredients: [{type: mongoose.Schema.Types.ObjectId, ref: 'Ingredient'}],
    type: {type: mongoose.Schema.Types.String, required: false},
})


module.exports = mongoose.model('Meal', mealModel);
