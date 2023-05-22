const express = require('express');
const router = express.Router();
const {addNewTask, getEmployeeTask} = require('../controllers/taskController');

router.post('/addnewtask', addNewTask);
router.get('/getemployeetask/:employeeId', getEmployeeTask);

module.exports = router;
