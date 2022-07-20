import { useState, useEffect } from "react"
import React from 'react';
import axios from 'axios';


const baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs?select=*'

const Forms = () => {

    const [formData, setFormData] = useState({
        title: '',
        description: '',
        author:'',
        reading_time: '',
    });

    const fetchFormData = (e) =>{
        e.preventDefault()

        setFormData({
            ...formData,
            [e.target.name]:e.target.value,
        });
    }

    const submitFormData = (e) =>{
        e.preventDefault()
        
        axios.post(baseURL, formData, {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then((response) => {
          console.log(response)  
        });
    }

    console.log("29",formData);
    return(
            <div className='forms container'>
            <h2>Add Blogs!!</h2>
            <form className="form-inline" >
                <div className="form-group">
                    <label for="title">Title</label>
                    <input type="text" className="form-control" id="title" onChange={fetchFormData} placeholder="Enter Blog title" name="title"  />
                </div>

                <div className="form-group">
                    <label for="descrip">Description</label>
                    <textarea class="form-control" id="descrip" rows="3" name="description" onChange={fetchFormData} placeholder= "Enter Description"></textarea>
                </div>

                <div className="form-group">
                    <label for="author">Author Name</label>
                    <input type="text" className="form-control" id="author"  placeholder="Enter your Name" onChange={fetchFormData} name="author"/>
                </div>

                <div className="form-group">
                    <label for="time">Reading Time</label>
                    <input type="number" className="form-control" id="time"  placeholder="Enter Reading time" onChange={fetchFormData} name="reading_time"/>
                </div>
                
                <button type="submit" className="btn btn-primary" onClick={submitFormData}>Submit</button>
            </form>
            </div>
        );
}

export default Forms;