const mongoose = require('mongoose');

const signingModel = new mongoose.Schema({
    id: {type: mongoose.Schema.Types.ObjectId, required: true},
    password: {type: mongoose.Schema.Types.String, required: false, min: 5, max: 20},
    name: {type: mongoose.Schema.Types.String, required: true},
    role: {type: mongoose.Schema.Types.String,
        enum: ['Client', 'Manager', 'Chef', 'ChefHelper', 'Employee'], default: 'Client'},
    login: {type: mongoose.Schema.Types.String, required: true},

}, {timestamps: true});

module.exports = mongoose.model('Signing', signingModel);