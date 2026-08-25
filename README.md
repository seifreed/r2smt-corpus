# r2SMT corpus

This repository is the public, versioned fixture corpus for r2SMT's
end-to-end quality gates. Every fixture includes source or assembly inputs and
machine-readable branch, finding, and patch expectations.

The `manifest.json` schema is intentionally small and stable. The main r2SMT
repository pins a commit of this repository when running its benchmark gate;
the generated reports are release evidence, not hand-edited claims.

Fixtures currently cover control flow, data flow, portable relocatable objects,
and conservative boundary/unknown cases. New fixtures should state their
compiler, architecture, optimization, and feature coverage in the manifest
change that introduces them.
