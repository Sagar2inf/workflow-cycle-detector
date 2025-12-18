import { useState, useEffect } from "react";
import api from "./api";
import { set } from "mongoose";

function App() {
  const [nodeInput, setNodeInput] = useState("");
  const [edgeInput, setEdgeInput] = useState("");
  const [queryNode, setQueryNode] = useState("");
  const [output, setOutput] = useState("");

  // Graph status state
  const [graphStatus, setGraphStatus] = useState(null);

  // ---------- Graph Status ----------
  const getStats = async () => {
    try {
      const res = await api.get("/flags");
      setGraphStatus(res.data);
    } catch (err) {
      console.error("Failed to fetch graph status", err);
    }
  };

  // Call once on page load
  useEffect(() => {
    getStats();
  }, []);

  // ---------- Node Ops ----------
  const addNode = async () => {
    const res = await api.post("/node/add", { node: nodeInput });
    setOutput(res.data);
    getStats(); 
  };

  const deleteNode = async () => {
    const res = await api.post("/node/delete", { node: nodeInput });
    setOutput(res.data);
    getStats();
  };

  // ---------- Edge Ops ----------
  const addEdge = async () => {
    const res = await api.post("/edge/add", { edge: edgeInput });
    setOutput(res.data);
    getStats();
  };

  const deleteEdge = async () => {
    const res = await api.post("/edge/delete", { edge: edgeInput });
    setOutput(res.data);
    getStats();
  };

  // ---------- Queries ----------
  const getChildren = async () => {
    const res = await api.post("/query/children", { node: queryNode });
    setOutput(res.data);
  };

  const getParents = async () => {
    const res = await api.post("/query/parents", { node: queryNode });
    setOutput(res.data);
  };

  // ---------- Trees ----------
  const getflow = async () => {
    const res = await api.get("/tree/flow");
    setOutput(res.data);
  };

  // ---------- Clear data ----------
  const clearGraph = async () => {
    try {
      const res = await api.post("/graph/clear");
      setOutput(res.data);
      getStats();
    } catch (err) {
      console.error("Failed to clear graph", err);
    }
  };

  return (
    <div style={{ padding: "20px", fontFamily: "sans-serif" }}>
      <h2>Workflow Graph Engine</h2>

      {/* Live Graph Status (Top Right) */}
      <div
        style={{
          position: "fixed",
          top: "16px",
          right: "20px",
          padding: "12px 16px",
          background: "#111",
          color: "#0f0",
          borderRadius: "8px",
          fontSize: "14px",
          maxWidth: "280px",
          boxShadow: "0 4px 10px rgba(0,0,0,0.3)",
          zIndex: 1000
        }}
      >
        <strong>Graph Status</strong>
        <pre style={{ margin: 0, whiteSpace: "pre-wrap" }}>
          {graphStatus
            ? graphStatus
            : "Checking..."}
        </pre>
      </div>

      {/* Node Section */}
      <div>
        <h3>Node Operations</h3>
        <input
          placeholder="Node name (e.g. A)"
          value={nodeInput}
          onChange={(e) => setNodeInput(e.target.value)}
        />
        <button onClick={addNode}>Add Node</button>
        <button onClick={deleteNode}>Delete Node</button>
      </div>

      {/* Edge Section */}
      <div>
        <h3>Edge Operations</h3>
        <input
          placeholder="Edge (A -> B or A -{5}-> B)"
          value={edgeInput}
          onChange={(e) => setEdgeInput(e.target.value)}
          style={{ width: "300px" }}
        />
        <button onClick={addEdge}>Add Edge</button>
        <button onClick={deleteEdge}>Delete Edge</button>
      </div>

      {/* Queries */}
      <div>
        <h3>Queries</h3>
        <input
          placeholder="Node for query"
          value={queryNode}
          onChange={(e) => setQueryNode(e.target.value)}
        />
        <button onClick={getChildren}>Get Children</button>
        <button onClick={getParents}>Get Parents</button>
      </div>

      {/* Trees */}
      <div>
        <h3>Trees</h3>
        <button onClick={getflow}>Get working flow</button>
      </div>

      {/* Clear Graph */}
      <div style={{ marginTop: "16px" }}>
        <h3>Graph Controls</h3>
        <button
          onClick={clearGraph}
          style={{
            background: "#b00020",
            color: "white",
            padding: "6px 12px",
            borderRadius: "6px",
            border: "none",
            cursor: "pointer"
          }}
        >
          Clear Graph
        </button>
      </div>

      {/* Output */}
      <div style={{ marginTop: "20px" }}>
        <h3>Output</h3>
        <pre>{output}</pre>
      </div>
    </div>
  );
}

export default App;
