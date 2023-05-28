const mongoose = require('mongoose');

const taskModel = mongoose.Schema({
    name: {type: mongoose.Schema.Types.String, required: true},
    description: {type: mongoose.Schema.Types.String, required: true, default: ""},
    employeeId: {type: mongoose.Schema.Types.ObjectId, required: true},
    bossId: {type: mongoose.Schema.Types.ObjectId, required: true},
    done: {type: mongoose.Schema.Types.Boolean, required: true, default: false}
})

module.exports = mongoose.model('Task', taskModel);
