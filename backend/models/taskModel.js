const mongoose = require('mongoose');

const taskModel = mongoose.Schema({
    name: {type: mongoose.Schema.Types.String, required: true},
    description: {type: mongoose.Schema.Types.String, required: true, default: ""},
    employeeId: {type: mongoose.Schema.Types.Number, required: true},
})

module.exports = mongoose.model('Task', taskModel);
