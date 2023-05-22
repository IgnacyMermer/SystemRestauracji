const express = require('express');
const router = express.Router();
const {getEmployeeById} = require('../controllers/employeesController');

router.get('/employeebyid/:employeeId', getEmployeeById);

module.exports = router;