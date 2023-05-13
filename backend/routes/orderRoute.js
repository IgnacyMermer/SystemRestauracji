const express = require('express');
const router = express.Router();
const {addNewOrder} = require('../controllers/orderController');

router.post('/addneworder', addNewOrder);

module.exports = router;