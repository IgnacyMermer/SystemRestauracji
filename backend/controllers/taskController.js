const task = require('../models/taskModel');

exports.addNewTask = (req, res, status)=>{
    try{
        const {name, description, priority} = req.body;
        const newTask = new task({
            name,
            description,
            priority
        });
        newTask.save().then(newTask=>{
            return res.status(200).json({
                task: newTask
            })
        }).catch(error=>{
            return res.status(400).json({
                error
            })
        })
    }
    catch(error){
        return res.status(400).json({
            error
        })
    }
}