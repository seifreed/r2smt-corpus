# r2SMT corpus

This repository is the public, versioned fixture corpus for r2SMT's
end-to-end quality gates. Every fixture includes source or assembly inputs and
machine-readable branch, finding, and patch expectations.

The `manifest.json` schema is intentionally small and stable. The main r2SMT
repository pins a commit of this repository when running its benchmark gate;
the generated reports are release evidence, not hand-edited claims.

The current set has six executable fixtures: control-flow, dataflow,
edge-cases, loop-memory, signed-unsigned, and portable-matrix relocatable
objects. Together they exercise real and opaque branches, signed/unsigned
comparisons, bounded loops, volatile memory, calls, joins, subregisters,
partial flags, and deliberately conservative unknown cases. The portable
matrix adds six x86, x86-64, AArch32, Thumb, and AArch64 object variants across
GCC/Clang and O0/O2/O3/Os.

The manifest's top-level compiler/architecture/optimization lists describe the
coverage contract; the generated matrix is the executable evidence for the
portable variants. New fixtures should state their compiler, architecture,
optimization, and feature coverage in the manifest change that introduces
them.

## Published baseline

[`metrics-baseline.json`](metrics-baseline.json) is a checked-in aggregate from
the r2SMT `real-binaries` gate. It records recall, actionable precision,
Unknown reasons, p50/p95 runtime, verified patch rate, and rollback rate, along
with the exact r2SMT, corpus, and radare2 revisions used to produce it. Refresh
it with:

```bash
scripts/quality-gates.sh real-binaries
cp target/r2smt-bench-metrics.json metrics-baseline.json
```

The baseline is evidence, not a release threshold: a null precision means the
run produced no actionable findings to score.
