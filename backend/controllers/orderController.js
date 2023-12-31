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

exports.getAllClientOrders = (req, res, status)=>{
    try{
        const{clientId} = req.params;
        order.find({clientId: clientId}).populate('mealsIds').exec().then(orders=>{
            if(orders!=undefined){
                return res.status(200).json({
                    orders
                });
            }
            else{
                return res.status(400).json({
                    error: "Error during get orders"
                })
            }
        })
    }
    catch(e){
        return res.status(400).json({
            error
        });
    }
}

exports.getOrderById = (req, res, status)=>{
    try{
        const {orderId} = req.params;
        order.findOne({_id: orderId}).populate('mealsIds').exec().then(order=>{
           if(order!=undefined){
               return res.status(200).json({
                  order
               });
           }
           else{
                return res.status(400).json({
                    error: "No order found"
                });
           }
        });
    }
    catch(e){
        return res.status(400).json({
            error:e
        });
    }
}

exports.getALlOrders = (req, res, status)=>{
    try{
        order.find({status: 'in progress'}).populate('mealsIds clientId').exec().then(orders=>{
            if(orders!=undefined){
                return res.status(200).json({
                    orders
                });
            }
            else{
                return res.status(400).json({
                    error: "No order found"
                });
            }
        });
    }
    catch (e) {
        return res.status(400).json({
            error:e
        });
    }
}

exports.setOrderAsDone = (req, res ,status)=>{
    const{id} = req.params;
    try{
        order.findOneAndUpdate({_id: id}, {status: "done"}).exec().then(newOrder=>{
            return res.status(200).json({
                order: newOrder
            });
        })
    }
    catch (e) {
        return res.status(400).json({
            error:e
        });
    }
}