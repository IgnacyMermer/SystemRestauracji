const express = require('express');
const router = express.Router();
const {addNewTask, getEmployeeTask, getEmployeeTaskByName, changeDone, getEmployeeTaskUnDone} = require('../controllers/taskController');

router.post('/addnewtask', addNewTask);
router.get('/getemployeetask/:employeeId', getEmployeeTask);
router.get('/getemployeetaskundone/:employeeId', getEmployeeTaskUnDone);
router.get('getemployeetaskbyname/:employeeName', getEmployeeTaskByName);
router.post('/changetaskdone/:id', changeDone);

module.exports = router;
