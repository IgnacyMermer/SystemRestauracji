const signings = require('../models/signingModel');

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