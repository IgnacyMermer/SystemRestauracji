const mongoose = require('mongoose');

const taskModel = mongoose.Schema({
    name: {type: mongoose.Schema.Types.String, required: true},
    description: {type: mongoose.Schema.Types.String, required: true, default: ""},
    priority: {type: mongoose.Schema.Types.Number, default: 1},
})

module.exports = mongoose.model('Task', taskModel);
