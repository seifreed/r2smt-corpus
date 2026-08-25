# Edge cases fixture

This fixture intentionally combines a volatile memory update, a bounded loop,
and a non-inlined call boundary. It is compiled by the host benchmark runner
and is expected to exercise conservative `Unknown`/boundary reporting rather
than force a fabricated actionable finding.
