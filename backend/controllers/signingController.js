const signing = require('../models/signingModel');


exports.signIn = (req, res, status)=>{
    try{
        //it needs crypting, bcrypt library imo
        signing.findOne({login: req.body.login, password: req.body.password}).exec().then(async user=>{
            if(user!=undefined){
                return res.status(200).json({
                    user
                });
            }
            else{
                return res.status(400).json({
                    error: "Wrong credentials"
                });
            }
        })
    }
    catch(e){
        return res.status(400).json({
            error: e
        });
    }
}

exports.signUp = (req, res, status)=>{
    const {login, password, name} = req.body
    let role = req.body.role;
    try{
        signing.findOne({email: req.body.email}).exec().then(async user=>{
            if(user){
                return res.status(400).json({
                    message: 'User already exists'
                })
            }
            else{
                const user = new signing({
                    login,
                    //crypting
                    password,
                    name,
                    role
                });

                user.save().then(user=>{
                    res.status(200).json({
                        message: "Signed up",
                        user,
                    })
                }).catch(error=>{
                    return res.status(400).json({
                        error
                    })
                })
            }
        })
    }
    catch(e){
        return res.status(400).json({
            error: e
        })
    }
}