const express = require('express');
const router = express.Router();
const {getAllEmployees, getEmployeeById, getEmployeeByName} = require('../controllers/employeesController');

router.get('/getallemploees', getAllEmployees);
router.get('/employeebyid/:employeeId', getEmployeeById);
router.get('/employeebyname/:employeeName', getEmployeeByName);

module.exports = router;