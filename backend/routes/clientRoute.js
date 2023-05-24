const{getAllClients} = require('../controllers/clientController');
const express = require('express');
const router = express.Router();


router.get('/getallclients', getAllClients);

module.exports = router;