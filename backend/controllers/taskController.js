const task = require('../models/taskModel');

exports.addNewTask = (req, res, status)=>{
    try{
        const {name, description, employeeId, bossId} = req.body;
        const newTask = new task({
            name,
            description,
            employeeId,
            bossId
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
        const {employeeId} = req.params;
        task.find({employeeId: employeeId}).populate('name').exec().then(tasks=>{
            if(tasks!=undefined){
                return res.status(200).json({
                    tasks
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

exports.getEmployeeTaskByName = (req, res, status)=>{
    try{
        const {employeeName} = req.params;
        task.find({employeeName: employeeName}).populate('name').exec().then(tasks=>{
            if(tasks!=undefined){
                return res.status(200).json({
                    tasks
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

exports.changeDone = (req, res, status)=>{
    try {
        const{id} = req.params;
        const{done} = req.body;
        console.log(done);
        task.findOneAndUpdate({_id:id}, {done:done}).exec().then(newTask=>{
            if(newTask!=undefined){
                return res.status(200).json({
                    taks: newTask
                });
            }
            else{
                return res.status(400).json({
                    error: "Error during changing task's done"
                });
            }
        })
    }
    catch(e){
        return res.status(400).json({
            error
        });
    }
}
