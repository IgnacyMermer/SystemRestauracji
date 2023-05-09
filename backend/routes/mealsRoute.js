const express = require('express');
const router = express.Router();
const {getAllIngredients, addNewIngredient} = require('../controllers/mealsController');

router.get('/getallingredients',getAllIngredients);
router.post('/addnewingredient', addNewIngredient);

module.exports = router;