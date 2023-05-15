const express = require('express');
const router = express.Router();
const {getAllIngredients, addNewIngredient, getAllMeals, addNewMeal, changeMealAvailability} =
    require('../controllers/mealsController');

router.get('/getallingredients',getAllIngredients);
router.get('/getallmeals',getAllMeals);
router.post('/addnewingredient', addNewIngredient);
router.post('/addnewmeal', addNewMeal);
router.post('/changemealavailability/:id', changeMealAvailability);

module.exports = router;