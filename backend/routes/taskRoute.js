const express = require('express');
const router = express.Router();
const {addNewTask} = require('../controllers/taskController');

router.post('/addnewtask', addNewTask);

module.exports = router;
