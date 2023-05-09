
const ingredient = require('../models/mealsModel');

exports.getAllIngredients = (req, res, status)=>{
    try{
        ingredient.find({}).exec().then(async ingredients=>{
            if(ingredients!=undefined){
                return res.status(200).json({
                    ingredients
                })
            }
            else{
                return res.status(400).json({
                    error: "Error during get ingredients"
                })
            }
        })
    }
    catch (e) {
        return res.status(400).json({
            error: e
        })
    }
}

exports.addNewIngredient = (req, res, status)=>{
    try{
        const {productsCount, shortName, name} = req.body;
        const newIngredient = new ingredient({
            shortName,
            name,
            productsCount
        });
        newIngredient.save().then(ingredient=>{
            return res.status(200).json({
                ingredient
            });
        }).catch(e=>{
            return res.status(400).json({
                error: e
            })
        })
    }
    catch(e){
        return res.status(400).json({
            error: e
        });
    }
}