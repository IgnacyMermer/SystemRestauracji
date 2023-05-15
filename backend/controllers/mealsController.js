
const ingredient = require('../models/ingredientModel');
const meal = require('../models/mealsModel')


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

exports.getAllMeals = (req, res, status)=>{
    try{
        meal.find({}).populate('ingredients').exec().then(async meals=>{
            if(meals!=undefined){
                return res.status(200).json({
                    meals
                })
            }
            else{
                return res.status(400).json({
                    error: "Error during get ingredients"
                })
            }
        })
    }
    catch(e){
        return res.status(400).json({
            error: e
        });
    }
}

exports.addNewMeal = (req, res, status)=>{
    try{
        const {productsCount, shortName, name, price, ingredients, description} = req.body;
        const newMeal = new meal({
            shortName,
            name,
            description,
            productsCount,
            price,
            ingredients
        });
        newMeal.save().then(meal=>{
            return res.status(200).json({
                meal
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
