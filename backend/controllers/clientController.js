const signings = require('../models/signingModel');
const orders = require('../models/orderModel');

exports.getAllClients = (req, res, status)=>{
    try{
        signings.find({role: 'Client'}).exec().then(clients=>{
            if(clients!=undefined){
                return res.status(200).json({
                    clients
                });
            }
            else{
                return res.status(400).json({
                    error: "Error during getting clients"
                })
            }
        });
    }
    catch(e){
        return res.status(400).json({
            error: e
        });
    }
}

exports.getClientOrders = (req, res, status)=>{
    try{
        const{clientId} = req.params;
        orders.find({clientId}).exec().then(clientOrders=>{
            if(clientOrders!=undefined){
                return res.status(200).json({
                    orders: clientOrders
                });
            }
            else{
                return res.status(400).json({
                    error: "Error during getting orders"
                });
            }
        })
    }
    catch (e) {
        return res.status(400).json({
            error: e
        });
    }
}