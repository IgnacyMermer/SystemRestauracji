const express = require('express');
const router = express.Router();
const {addNewTask, getEmployeeTask, getEmployeeTaskByName} = require('../controllers/taskController');

router.post('/addnewtask', addNewTask);
router.get('/getemployeetask/:employeeId', getEmployeeTask);
router.get('getemployeetaskbyname/:employeeName', getEmployeeTaskByName);

module.exports = router;
