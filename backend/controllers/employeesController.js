const employees = require('../models/employeesModel');

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
