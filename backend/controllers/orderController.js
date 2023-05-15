const order = require('../models/orderModel');

exports.addNewOrder = (req, res, status) => {
    try{
        const {totalPrice, mealsIds, clientId} = req.body;
        const newOrder = new order({
            totalPrice,
            mealsIds,
            clientId
        })
        newOrder.save().then(newOrder=>{
            return res.status(200).json({
                order: newOrder
            })
        }).catch(error=>{
            return res.status(400).json({
                error
            })
        })
    }
    catch(error){
        return res.status(400).json({
            error
        })
    }
}