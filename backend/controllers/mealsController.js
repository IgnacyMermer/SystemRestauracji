
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

exports.getAllMealsAvailable = (req, res, status)=>{
    try{
        meal.find({availability: true}).populate('ingredients').exec().then(async meals=>{
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
        let type = req.body.type;
        if(type==undefined){
            type="meal";
        }
        const newMeal = new meal({
            shortName,
            name,
            description,
            productsCount,
            price,
            ingredients,
            type
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

exports.changeMealAvailability = (req, res, status)=>{
    try{
        const {availability} = req.body;
        const {id} = req.params;
        meal.findOneAndUpdate({_id: id}, {availability: availability}).then(meal=>{
            return res.status(200).json({
                meal
            });
        }).catch(error=>{
            return res.status(400).json({
                error
            });
        })

    }
    catch(e){
        return res.status(400).json({
            error: e
        });
    }
}

exports.removeMeal = (req, res, status)=>{
    try{
        const{mealId} = req.params;
        meal.findByIdAndRemove({_id: mealId}).exec().then(result=>{
           if(result!=undefined){
               return res.status(200).json({
                   message: "Meal removed"
               });
           }
           else{
               return res.status(400).json({
                   error: "Error during removing meal from db"
               });
           }
        });
    }
    catch(e){
        return res.status(400).json({
            error: e
        });
    }
}