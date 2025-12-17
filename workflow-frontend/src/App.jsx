import { useState } from "react";
import api from "./api";

function App() {
  const [nodeInput, setNodeInput] = useState("");
  const [edgeInput, setEdgeInput] = useState("");
  const [queryNode, setQueryNode] = useState("");
  const [output, setOutput] = useState("");

  // ---------- Node Ops ----------
  const addNode = async () => {
    const res = await api.post("/node/add", { node: nodeInput });
    setOutput(JSON.stringify(res.data, null, 2));
  };

  const deleteNode = async () => {
    const res = await api.post("/node/delete", { node: nodeInput });
    setOutput(JSON.stringify(res.data, null, 2));
  };

  // ---------- Edge Ops ----------
  const addEdge = async () => {
    const res = await api.post("/edge/add", { edge: edgeInput });
    setOutput(JSON.stringify(res.data, null, 2));
  };

  const deleteEdge = async () => {
    const res = await api.post("/edge/delete", { edge: edgeInput });
    setOutput(JSON.stringify(res.data, null, 2));
  };

  // ---------- Queries ----------
  const getChildren = async () => {
    const res = await api.post("/query/children", { node: queryNode });
    setOutput(JSON.stringify(res.data, null, 2));
  };

  const getParents = async () => {
    const res = await api.post("/query/parents", { node: queryNode });
    setOutput(JSON.stringify(res.data, null, 2));
  };

  // ---------- Trees ----------
  const getMinTree = async () => {
    const res = await api.get("/tree/min");
    setOutput(JSON.stringify(res.data, null, 2));
  };

  const getRandomTree = async () => {
    const res = await api.get("/tree/random");
    setOutput(JSON.stringify(res.data, null, 2));
  };

  // ---------- Flags ----------
  const getFlags = async () => {
    const res = await api.get("/flags");
    setOutput(JSON.stringify(res.data, null, 2));
  };

  return (
    <div style={{ padding: "20px", fontFamily: "sans-serif" }}>
      <h2>Workflow Graph Engine</h2>

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
          placeholder='Edge (A -> B or A -{5}-> B)'
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
        <button onClick={getMinTree}>Get Minimum Tree</button>
        <button onClick={getRandomTree}>Get Random Tree</button>
      </div>

      {/* Flags */}
      <div>
        <h3>Graph Flags</h3>
        <button onClick={getFlags}>Check Graph Status</button>
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
