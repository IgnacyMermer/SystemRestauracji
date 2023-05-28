const express = require('express');
const router = express.Router();
const {addNewOrder, getAllClientOrders, getOrderById, getALlOrders,
    setOrderAsDone} = require('../controllers/orderController');

router.post('/addneworder', addNewOrder);
router.get('/getclientorders/:clientId', getAllClientOrders);
router.get('/getorder/:orderId', getOrderById);
router.get('/getallorders', getALlOrders);
router.post('/setstatusdone/:id', setOrderAsDone);

module.exports = router;
