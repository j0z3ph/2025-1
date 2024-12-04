using System;
using System.Collections.Generic;

namespace HolaMundo.Models;

public partial class Sale
{
    public int SalesId { get; set; }

    public int SalesPersonId { get; set; }

    public int CustomerId { get; set; }

    public int ProductId { get; set; }

    public int Quantity { get; set; }

    public virtual Customer Customer { get; set; } = null!;

    public virtual Product Product { get; set; } = null!;

    public virtual Employee SalesPerson { get; set; } = null!;
}
