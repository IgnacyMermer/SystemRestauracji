const task = require('../models/taskModel');

exports.addNewTask = (req, res, status)=>{
    try{
        const {name, description, employeeId} = req.body;
        const newTask = new task({
            name,
            description,
            employeeId
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

exports.getEmployeeTask = (req, res, status)=>{
    try{
        const{employeeId} = req.params;
        task.find({employeeId: employeeId}).populate('name').exec().then(task=>{
            if(task!=undefined){
                return res.status(200).json({
                    task
                });
            }
            else{
                return res.status(400).json({
                    error: "Error during get task"
                })
            }
        })
    }
    catch(e){
        return res.status(400).json({
            error
        });
    }
}