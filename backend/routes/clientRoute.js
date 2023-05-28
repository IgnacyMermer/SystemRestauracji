const{getAllClients, getClientOrders} = require('../controllers/clientController');
const express = require('express');
const router = express.Router();


router.get('/getallclients', getAllClients);
router.get('/getclientorders', getClientOrders);

module.exports = router;