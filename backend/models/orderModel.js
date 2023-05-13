const mongoose = require('mongoose');

const orderModel = mongoose.Schema({
    id: {type: mongoose.Schema.Types.Number, required: true},
    totalPrice: {type: mongoose.Schema.Types.Number, required: true},
    mealsIds: {type: mongoose.Schema.Types.Number, required: true},
    clientId: {type: mongoose.Schema.Types.Number, required: true},
})

module.exports = mongoose.model('Order', orderModel);