const mongoose = require('mongoose');

const orderModel = mongoose.Schema({
    totalPrice: {type: mongoose.Schema.Types.Number, required: true},
    mealsIds: [{ref: 'Meal', type: mongoose.Schema.Types.ObjectId}],
    clientId: {ref: 'Signing', type: mongoose.Schema.Types.ObjectId},
}, { timestamps: true })

module.exports = mongoose.model('Order', orderModel);