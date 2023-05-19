const express = require('express');
const router = express.Router();
const {addNewOrder, getAllClientOrders} = require('../controllers/orderController');

router.post('/addneworder', addNewOrder);
router.get('/getclientorders/:clientId', getAllClientOrders);

module.exports = router;