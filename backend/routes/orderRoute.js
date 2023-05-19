const express = require('express');
const router = express.Router();
const {addNewOrder, getAllClientOrders, getOrderById} = require('../controllers/orderController');

router.post('/addneworder', addNewOrder);
router.get('/getclientorders/:clientId', getAllClientOrders);
router.get('/getorder/:orderId', getOrderById);

module.exports = router;