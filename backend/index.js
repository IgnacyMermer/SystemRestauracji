const express = require('express');
const cors = require('cors');
const mongoose = require('mongoose');
const env = require('dotenv').config();
const signingRoute = require('./routes/signingRoute');

const app = express();

app.get('/src/app.js', (req, res, status)=>{
    return res.status(200).json({
        "message": "Hello world!"
    });
});

app.use(cors());
app.use(express.json());

mongoose.connect(`mongodb+srv://${process.env.DB_USERNAME}:${process.env.DB_PASSWORD}@cluster0.ibz2cqr.mongodb.net/${process.env.DB_NAME}?retryWrites=true&w=majority`,
    {
        useUnifiedTopology: true,
        useNewUrlParser: true
    }).then(result=>{
    console.log('database connected')
}).catch(err=>{
    console.log(err);
});

app.use('/', signingRoute);

app.listen(3000);
