const mongoose = require('mongoose');

const ingredientModel = new mongoose.Schema({
    shortName: {type: mongoose.Schema.Types.String, required: true},
    name: {type: mongoose.Schema.Types.String, required: true},
    availability: {type: mongoose.Schema.Types.Boolean, required:true, default: true},
    productsCount: {type: mongoose.Schema.Types.Number, required: true, default: 0}
});

module.exports = mongoose.model('Ingredient', ingredientModel);
