using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace login_webapp.Models
{
    public class UserContext : DbContext
    {
        public UserContext(DbContextOptions options) : base(options)
        { }
        
        public DbSet<User> User { get; set; }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>().HasData(
                new User() { Id = 1, Username = "a", Email = "a@gmail.com",  Password = "abc" },
                new User() { Id = 2, Username = "b", Email = "b@gmail.com", Password = "bcd" },
                new User() { Id = 3, Username = "c", Email = "c@gmail.com",  Password = "cde" });
        }
    }
    
}
