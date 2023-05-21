const mongoose = require('mongoose');

const employeeModel = mongoose.Schema({
    id: {type: mongoose.Schema.Types.Number, required: true},
    name: {type: mongoose.Schema.Types.String, required: true},
    role: {type: mongoose.Schema.Types.String, required: true},
    email: {type: mongoose.Schema.Types.String, default: 'none'},
    task : {type: mongoose.Schema.Types.Boolean, default: false},
})

module.exports = mongoose.model('Employee', employeeModel);
