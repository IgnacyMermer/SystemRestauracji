const employees = require('../models/employeesModel');
const signings = require('../models/signingModel');

exports.getAllEmployees = (req, res, status)=>{
    try{
        employees.find({}).exec().then(async employee=>{
            if(employee!=undefined){
                return res.status(200).json({
                    employee
                })
            }
            else{
                return res.status(400).json({
                    error: "Error during get employee"
                })
            }
        })
    }
    catch (e) {
        return res.status(400).json({
            error: e
        })
    }
}

exports.getEmployeeById = (req, res, status)=>{
    try{
        const {employeeId} = req.params;
        signings.find({_id: employeeId}).exec().then(employee=>{
            if(employee!=undefined){
                return res.status(200).json({
                    employee
                })
            }
            else{
                return res.status(400).json({
                    error: "Error during get emplyee"
                })
            }
        })
    }
    catch (e) {
        return res.status(400).json({
            error: e
        });
    }
}
