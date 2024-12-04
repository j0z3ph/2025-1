using System;
using System.Collections.Generic;
using System.ComponentModel;

namespace HolaMundo.Models;

public partial class Employee
{
    public int EmployeeId { get; set; }
    [DisplayName("Nombre")]
    public string FirstName { get; set; } = null!;

    public string? MiddleInitial { get; set; }

    public string LastName { get; set; } = null!;

    public virtual ICollection<Sale> Sales { get; set; } = new List<Sale>();
}
